/* ------------------------------
   $Id: sighandlers.c,v 1.1 2005/03/17 13:00:46 marquet Exp $
   ------------------------------------------------------------

   mshell - a job manager
   
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>
#include <assert.h>


#include "jobs.h"
#include "common.h"
#include "sighandlers.h"


/*
 * Signal - wrapper for the sigaction function
 */
int
signal_wrapper(int signum, handler_t *handler) 
{
  /*A sigaction structure*/
  struct sigaction sa;
  /*The function handler is defined in the sa_handler field*/
  sa.sa_handler = handler;
  /*We put empty signal on the sa_mask of the structure*/
  sigemptyset(&sa.sa_mask);
  /*sa_flags is set to SA_RESTART*/
  sa.sa_flags = SA_RESTART;
  /*We return the sigaction of the signum*/
  return sigaction(signum, &sa, NULL);
  
}


/* 
 * sigchld_handler - The kernel sends a SIGCHLD to the shell whenever
 *     a child job terminates (becomes a zombie), or stops because it
 *     received a SIGSTOP or SIGTSTP signal. The handler reaps all
 *     available zombie children
 */
void
sigchld_handler(int sig) 
{
  /*Pid had return by the waitpid() function*/
  pid_t pidReturned;
  /*Status for the waitpid()*/
  int status;
  /*Pointer of a job's structure*/
  struct job_t* jobSon;
  
  if (verbose)
    printf("sigchld_handler: entering\n");
  
  /*We want all the child's pid, so we make the 1rst argument to -1, we have to see if the pid returned an integer at least 1*/
  while((pidReturned = waitpid(-1, &status, WNOHANG | WUNTRACED)) > 0) {
    /*We get the job structure of pidReturned*/
    jobSon = jobs_getjobpid(pidReturned);
    /*Add the command cause pipe not considered as new job/process*/
    if (jobSon == NULL) continue;
    /*We want to see all the process*/
    /*If the process finished normally, we delete the job*/
    if (WIFEXITED(status)) {
      if (verbose) printf("Pid finished normally %d\n", pidReturned);
      assert(jobs_deletejob(pidReturned));
    }
    /*If the process had been terminated by a signal, we delete the job*/
    if (WIFSIGNALED(status)) {
      if (verbose) printf("Pid terminated %d, by signal %d\n",pidReturned, WTERMSIG(status));
      assert(jobs_deletejob(pidReturned));
    }
    /*If the process had been stopped, we change the state of the pid's job on STOP(ST)*/
    if (WIFSTOPPED(status)) {
      if (verbose) printf("Pid stopped %d, by signal %d\n",pidReturned, WSTOPSIG(status));
      jobSon->jb_state = ST;
    }
  }
  
  if (verbose)
    printf("sigchld_handler: exiting\n");
    
  return;
}

/* 
 * sigintstp_handler - The kernel sends a SIGINT or SIGSTP to the shell whenver the
 *    user types ctrl-c or ctrl-z at the keyboard.  Catch it and send it along
 *    to the foreground job.  
 */
void
sigintstp_handler(int sig) 
{
  
  /*Pid foreground*/
  pid_t pidfg;
  
  (verbose && sig==SIGINT)?printf("sigint_handler: entering\n"):printf("sigstp_handler: entering\n");
  
  pidfg = jobs_fgpid();
  if (pidfg>0) 
    kill(pidfg, sig);
  
  (verbose && sig==SIGINT)?printf("sigint_handler: exiting\n"):printf("sigstp_handler: exiting\n");
  
  return;
}

