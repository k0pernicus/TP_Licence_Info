import java.io.*;
import java.lang.String;
import java.util.*;
import java.lang.Class;
import java.lang.System;
import java.lang.Math;


public class Mesure{


    /** tSize[] contient, par ordre croissant, toutes les tailles de
     * donnees pour lesquelles les temps d'execution des algorithmes
     * seront mesures par l'une des methodes mesureNomAlgorithme sur
     * l'objet de type Mesure. */
    int tSize[];
    /** tRep[i] contient le nombre de donnees differentes toutes de
     * taille tSize[i] sur lequel la moyenne des temps d'executions
     * sera calculee par l'une des methodes mesureNomAlgorithme sur
     * l'objet de type Mesure.*/
    int tRep[];
    /** tRes[i] contient a l'issue d'une mesure effectuee par une
     * methode mesureNomAlgorithme le temps moyen d'execution de
     * l'algorithme NomAlgorithme sur tRep[i] donnees differentes de
     * taille tSize[i] .*/
    double tRes[];

    /**************************************************************************
     **************************************************************************
     **************************** CONSTRUCTEUR ********************************
     **************************************************************************
     *************************************************************************/

    public Mesure(int[] tSize, int[] tRep){
	this.tSize = tSize;
	this.tRep = tRep;
	this.tRes = new double[tSize.length];

	for(int i = 0; i < this.tRes.length ; i++){
	    this.tRes[i] = 0;
	} 
	
    }
  

    /**************************************************************************
     **************************************************************************
     ************************ MESURE DES ALGORITHMES **************************
     **************************************************************************
     *************************************************************************/


    /** ecrit dans tRes[] les moyennes de temps de calcul de rechercheL
     * sur les nombres contenus dans tRep[] d'executions sur des donnees
     * dont les tailles sont indiquees dans tSize[], pour la recherche
     * de l'element 0 qui est contenu dans L */

    public void mesureRechercheL(){
	double startTime;
	double totalTime;
	boolean present;

	this.resetRes();
	
	  for (int i=0; i < this.tSize.length; i++){

	      Methodes M = new Methodes(this.tSize[i]);

	      for(int j = 0; j < this.tRep[i]; j++){	      

		  M.aleaL(); /** nouvelle instance */
		  
		  startTime = System.nanoTime();
		  present = M.rechercheL(0);
		  totalTime = (System.nanoTime() - startTime);
		  this.tRes[i] = this.tRes[i] + totalTime;
	      }
	      this.tRes[i] = this.tRes[i]/this.tRep[i];
	
	  }
    }
   /** ecrit dans tRes[] les moyennes de temps de calcul de rechercheT
     * sur les nombres contenus dans tRep[] d'executions sur des donnees
     * dont les tailles sont indiquees dans tSize[], pour la recherche
     * de l'element 0 qui est contenu dans T */

    public void mesureRechercheT(){
	double startTime;
	double totalTime;
	boolean present;

	this.resetRes();
	
	  for (int i=0; i < this.tSize.length; i++){

	      Methodes M = new Methodes(this.tSize[i]);

	      for(int j = 0; j < this.tRep[i]; j++){	      

		  M.aleaT(); /** nouvelle instance */
		  
		  startTime = System.nanoTime();
		  present = M.rechercheT(0);
		  totalTime = (System.nanoTime() - startTime);
		  this.tRes[i] = this.tRes[i] + totalTime;
	      }
	      this.tRes[i] = this.tRes[i]/this.tRep[i];
	
	  }
    }


    /** ecrit dans tRes[] les moyennes de temps de calcul de
     * minimumSimpleL sur les nombres contenus dans tRep[] d'executions
     * sur des donnees dont les tailles sont indiquees dans tSize[] */

    public void mesureMinimumSimpleL(){
	double startTime;
	double totalTime;
	int min;

	this.resetRes();
	
	  for (int i=0; i < this.tSize.length; i++){

	      Methodes M = new Methodes(this.tSize[i]);

	      for(int j = 0; j < this.tRep[i]; j++){	      

		  M.aleaL(); /** nouvelle instance */
		  
		  startTime = System.nanoTime();
		  min = M.minimumSimpleL();
		  totalTime = (System.nanoTime() - startTime);
		  this.tRes[i] = this.tRes[i] + totalTime;
	      }
	      this.tRes[i] = this.tRes[i]/this.tRep[i];
	
	  }
    }
    /** ecrit dans tRes[] les moyennes de temps de calcul de
     * minimumSimpleT sur les nombres contenus dans tRep[] d'executions
     * sur des donnees dont les tailles sont indiquees dans tSize[] */

    public void mesureMinimumSimpleT(){
	double startTime;
	double totalTime;
	int min;
	
	this.resetRes();

	  for (int i=0; i < this.tSize.length; i++){

	      Methodes M = new Methodes(this.tSize[i]);

	      for(int j = 0; j < this.tRep[i]; j++){	      

		  M.aleaT(); /** nouvelle instance */
		  
		  startTime = System.nanoTime();
		  min = M.minimumSimpleT();
		  totalTime = (System.nanoTime() - startTime);
		  this.tRes[i] = this.tRes[i] + totalTime;
	      }
	      this.tRes[i] = this.tRes[i]/this.tRep[i];
	
	  }
    }

    /** ecrit dans tRes[] les moyennes de temps de calcul de minimumTriL
     * sur les nombres contenus dans tRep[] d'executions sur des donnees
     * dont les tailles sont indiquees dans tSize[] */

    public void mesureMinimumTriL(){
	double startTime;
	double totalTime;
	int min;
	
	this.resetRes();

	  for (int i=0; i < this.tSize.length; i++){

	      Methodes M = new Methodes(this.tSize[i]);

	      for(int j = 0; j < this.tRep[i]; j++){	      

		  M.aleaL(); /** nouvelle instance */
		  
		  startTime = System.nanoTime();
		  min = M.minimumTriL();
		  totalTime = (System.nanoTime() - startTime);
		  this.tRes[i] = this.tRes[i] + totalTime;
	      }
	      this.tRes[i] = this.tRes[i]/this.tRep[i];
	
	  }
    }
    /** ecrit dans tRes[] les moyennes de temps de calcul de minimumTriT
     * sur les nombres contenus dans tRep[] d'executions sur des donnees
     * dont les tailles sont indiquees dans tSize[] */

    public void mesureMinimumTriT(){
	double startTime;
	double totalTime;
	int min;
	
	this.resetRes();

	  for (int i=0; i < this.tSize.length; i++){

	      Methodes M = new Methodes(this.tSize[i]);

	      for(int j = 0; j < this.tRep[i]; j++){	      

		  M.aleaT(); /** nouvelle instance */
		  
		  startTime = System.nanoTime();
		  min = M.minimumTriT();
		  totalTime = (System.nanoTime() - startTime);
		  this.tRes[i] = this.tRes[i] + totalTime;
	      }
	      this.tRes[i] = this.tRes[i]/this.tRep[i];
	
	  }
    }


    /** ecrit dans tRes[] les moyennes de temps de calcul de mystereL sur
     * les nombres contenus dans tRep[] d'executions sur des donnees
     * dont les tailles sont indiquees dans tSize[] */

    public void mesureMystereL(){
	double startTime;
	double totalTime;
	
	this.resetRes();

	  for (int i=0; i < this.tSize.length; i++){

	      Methodes M = new Methodes(this.tSize[i]);

	      for(int j = 0; j < this.tRep[i]; j++){	      

		  M.aleaL(); /** nouvelle instance */
		  
		  startTime = System.nanoTime();
		  M.mystereL();
		  totalTime = (System.nanoTime() - startTime);
		  this.tRes[i] = this.tRes[i] + totalTime;
	      }
	      this.tRes[i] = this.tRes[i]/this.tRep[i];
	
	  }
    }
    /** ecrit dans tRes[] les moyennes de temps de calcul de mystereT sur
     * les nombres contenus dans tRep[] d'executions sur des donnees
     * dont les tailles sont indiquees dans tSize[] */

    public void mesureMystereT(){
	double startTime;
	double totalTime;
	
	this.resetRes();

	  for (int i=0; i < this.tSize.length; i++){

	      Methodes M = new Methodes(this.tSize[i]);

	      for(int j = 0; j < this.tRep[i]; j++){	      

		  M.aleaT(); /** nouvelle instance */
		  
		  startTime = System.nanoTime();
		  M.mystereT();
		  totalTime = (System.nanoTime() - startTime);
		  this.tRes[i] = this.tRes[i] + totalTime;
	      }
	      this.tRes[i] = this.tRes[i]/this.tRep[i];
	
	  }
    }

    /** ecrit dans tRes[] les moyennes de temps de calcul de aleaL sur
     * les nombres contenus dans tRep[] d'executions sur des donnees
     * dont les tailles sont indiquees dans tSize[] */
    
    public void mesureAleaL(){
	double startTime;
	double totalTime;
	
	this.resetRes();

	for (int i=0; i < this.tSize.length; i++){
	    
	    Methodes M = new Methodes(this.tSize[i]);
	    
	    for(int j = 0; j < this.tRep[i]; j++){	      
		startTime = System.nanoTime();
		M.aleaL();
		totalTime = (System.nanoTime() - startTime);
		this.tRes[i] = this.tRes[i] + totalTime;
	    }
	    this.tRes[i] = this.tRes[i]/this.tRep[i];	
	}
    }
     /** ecrit dans tRes[] les moyennes de temps de calcul de aleaT sur
     * les nombres contenus dans tRep[] d'executions sur des donnees
     * dont les tailles sont indiquees dans tSize[] */
    
    public void mesureAleaT(){
	double startTime;
	double totalTime;

	this.resetRes();
	
	for (int i=0; i < this.tSize.length; i++){
	    
	    Methodes M = new Methodes(this.tSize[i]);
	    
	    for(int j = 0; j < this.tRep[i]; j++){	      
		startTime = System.nanoTime();
		M.aleaT();
		totalTime = (System.nanoTime() - startTime);
		this.tRes[i] = this.tRes[i] + totalTime;
	    }
	    this.tRes[i] = this.tRes[i]/this.tRep[i];	
	}
    }
   
    /**************************************************************************
     **************************************************************************
     *********************** FONCTIONS DE REFERENCE ***************************
     **************************************************************************
     *************************************************************************/


    /** ecrit dans tRes[] les valeurs de la fonction de reference log n
     * pour les valeurs de n contenues dans tSize[] */
    public void refLog (double k){
	for (int i=0; i < this.tSize.length; i++){
	    this.tRes[i] = Math.log(Math.pow(this.tSize[i],k));
	    }
    }

    /** ecrit dans tRes[] les valeurs de la fonction de reference n^k
     * pour les valeurs de n contenues dans tSize[] */
        public void refNpK (double k){
	for (int i=0; i < this.tSize.length; i++){
		this.tRes[i] = Math.pow(this.tSize[i],k);
	    }
    }

    /** ecrit dans tRes[] les valeurs de la fonction de reference n log n
     * pour les valeurs de n contenues dans tSize[] */
    public void refNlogn (){
	for (int i=0; i < this.tSize.length; i++){
	    this.tRes[i] = Math.log(this.tSize[i])*((double)this.tSize[i]);
	    }
    }

    /** ecrit dans tRes[] les valeurs de la fonction de reference exp
     * pour les valeurs de n contenues dans tSize[] */
    public void refExp (){
	for (int i=0; i < this.tSize.length; i++){
		this.tRes[i] = Math.exp(this.tSize[i]);
	    }
    }

    /** ecrit dans tRes[] les valeurs de la fonction de reference k^n
     * pour les valeurs de n contenues dans tSize[] */
    public void refKpN (double k){
	for (int i=0; i < this.tSize.length; i++){
	    this.tRes[i] = Math.pow(k,this.tSize[i]);
	    }
    }

    /**************************************************************************
     **************************************************************************
     ****************** RAPPORTS ENTRE FONCTIONS DE REFERENCE *****************
     **************************************************************************
     *************************************************************************/

    /** ecrit dans tRes[] les valeurs du rapport log(n)/log(n^k) pour
     * les valeurs de n contenues dans tSize[] */
     public void rapportLogLogK (double k){
	for (int i=0; i < this.tSize.length; i++){
	    this.tRes[i] =  Math.log(this.tSize[i])/Math.log(Math.pow(this.tSize[i],k));
	    }
    }
    /** ecrit dans tRes[] les valeurs du rapport log(n^k)/log(n) pour
     * les valeurs de n contenues dans tSize[] */
    public void rapportLogKLog (double k){
	for (int i=0; i < this.tSize.length; i++){
	    this.tRes[i] =  Math.log(Math.pow(this.tSize[i],k))/Math.log(this.tSize[i]);
	    }
    }

    /** ecrit dans tRes[] les valeurs du rapport (n^epsi)/log(n) pour
    * les valeurs de n contenues dans tSize[] */
    public void rapportNepsiLog (double epsi){
	for (int i=0; i < this.tSize.length; i++){
	    this.tRes[i] =  Math.pow(this.tSize[i],epsi)/Math.log(this.tSize[i]);
	    }
    }

    /** ecrit dans tRes[] les valeurs du rapport log(n)/(n^epsi) pour
    * les valeurs de n contenues dans tSize[] */
    public void rapportLogNepsi (double epsi){
	for (int i=0; i < this.tSize.length; i++){
	    this.tRes[i] = Math.log(this.tSize[i])/ Math.pow(this.tSize[i],epsi);
	    }
    }

    /** ecrit dans tRes[] les valeurs du rapport (2^n)/(n^k) pour les
    * valeurs de n contenues dans tSize[] */
    public void rapport2pNNpK (double k){
	for (int i=0; i < this.tSize.length; i++){
	    this.tRes[i] = Math.pow(2,this.tSize[i])/Math.pow(this.tSize[i],k);
	    }
    }

    /** ecrit dans tRes[] les valeurs du rapport (n^k)/(2^n) pour les
    * valeurs de n contenues dans tSize[] */
    public void rapportNpK2pN (double k){
	for (int i=0; i < this.tSize.length; i++){
	    this.tRes[i] = Math.pow(this.tSize[i],k)/Math.pow(2,this.tSize[i]);
	    }
    }

    /** ecrit dans tRes[] les valeurs du rapport (k^n)/(2^n) pour les
    * valeurs de n contenues dans tSize[] */
    public void rapportKpN2pN (double k){
	for (int i=0; i < this.tSize.length; i++){
	    this.tRes[i] = Math.pow(k,this.tSize[i])/Math.pow(2,this.tSize[i]);
	    }
    }
    /** ecrit dans tRes[] les valeurs du rapport (2^n)/(k^n) pour les
    * valeurs de n contenues dans tSize[] */
    public void rapport2pNKpN (double k){
	for (int i=0; i < this.tSize.length; i++){
	    this.tRes[i] = Math.pow(2,this.tSize[i])/Math.pow(k,this.tSize[i]);
	    }
    }

    /**************************************************************************
     **************************************************************************
     ************************* RESULTATS DES MESURES **************************
     **************************************************************************
     *************************************************************************/

    /** remise à 0 du tableau tRes[] */
    public void resetRes(){
	for (int i = 0; i < this.tRes.length; i++){
	    this.tRes[i] = 0;
	}
    }
   
    /** retourne une copie du tableau tRes[], pour recuperer les
     * resultats entre deux appels a des methodes mesureNomAlgorithme
     * ou refNomFonctionDeReference ou encore rapportNomsFonctions*/
    public double[] getRes(){
	
	double copie[] = new  double[this.tRes.length];
	for (int i = 0; i < this.tRes.length; i++){
	    copie[i] = this.tRes[i];
	}
	return copie;
    }

    
    /** retourne une copie du tableau tRes[] dont chaque element a ete
     * multiplie par le facteur factor */
    public double[] scaledRes(double factor){
	double[] tmp = new double[this.tRes.length];

	for (int i=0; i < this.tRes.length; i++){
	    tmp[i] = factor * this.tRes[i];
	}
	return tmp;
    }
  
    
    /** affiche les valeurs contenues dans le tableau a deux dimension
     * res en faisant preceder chaque ligne de la taille de donnee
     * contenue dans tSize[]. Les tableaux res[j] pour j verifiant 0
     * <= j < res.length sont ainsi affiches en colonnes successives
     * apres la colonne tSize[]. */
    public void output (double[][] res){
    
	    for (int i = 0 ; i < res[0].length ; i++) {
			System.out.print(""+this.tSize[i]);
		for (int j = 0 ; j < res.length ; j++) {
		    System.out.print(" "+res[j][i]);
		}
		System.out.print("\n");
	    }
	
    }

    /**************************************************************************
     **************************************************************************
     ********************************* MAIN ***********************************
     **************************************************************************
     *************************************************************************/


    public static void main(String[] arg) throws Exception {
	
	if (arg.length < 1){
	    System.out.println("toto !");
	}
	else {

	    int size0[] = {2,10,20,30,40,50,100,150,200,300,400,500,1000,1500,2000,5000,10000,25000,50000,75000,100000,250000,500000};
	    int rep0[] = {100,100,100,100,100,100,200,100,100,200,100,100,1,1,1,1,1,1,1,1,1,1,1};

	    //Tableau contenant des valeurs de répétition faibles
	    int rep1a[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	    //Tableau contenant des valeurs de répétition élevées
	    int rep1b[] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};
	    //Nombre de courbes concret, égal à 4
			

	    double scale0[] = {200,300,400,500,600};

	    int choix = Integer.parseInt(arg[0]);
	 
	    switch (choix) {
	    case 0:  /** Exemple */
		int nbCourbe0 = scale0.length + 1;
		double[][] res0 = new double[nbCourbe0][size0.length];
		Mesure M0 = new Mesure(size0,rep0);
		
		M0.mesureAleaT();
		res0[0] = M0.getRes();

		M0.refNpK(1);
		for (int i = 1 ; i < nbCourbe0 ; i++) {
		    res0[i] = M0.scaledRes(scale0[i-1]);
		}

		M0.output(res0);

		break;

		//Case permettant de répondre à la question 1
 	    case 1:
		int nbCourbe1 = 4;
			
		double[][] res1 = new double[nbCourbe1][size0.length];
			
		//M1a -> Mesures pour les valeurs de répétition faibles
		Mesure M1a = new Mesure (size0, rep1a);
		//M1b -> Mesures pour les valeurs de répétition élevées
		Mesure M1b = new Mesure (size0, rep1b);

		M1a.mesureAleaT();
		res1[0] = M1a.getRes();
		M1a.mesureAleaL();
		res1[1] = M1a.getRes();
			
		M1b.mesureAleaT();
		res1[2] = M1b.getRes();
		M1b.mesureAleaL();
		res1[3] = M1b.getRes();
			
		//Génération d'un fichier de sortie pour gnuplot
		M1a.output(res1);

		break;

		//Case permettant de répondre à la question 4
	    case 2:
		//Nombre de courbes concret, égal à 4
		int nbCourbe2 = 4;
			
		double[][] res2 = new double[nbCourbe2][size0.length];
			
		//M2a -> Mesures pour les valeurs de répétition faibles
		Mesure M2a = new Mesure (size0, rep1a);
		//M2b -> Mesures pour les valeurs de répétition élevées
		Mesure M2b = new Mesure (size0, rep1b);

		/*Mesures des recherches pour aleaT (voir méthode), répétitions faibles*/
		M2a.mesureRechercheT();
		res2[0] = M2a.getRes();
		M2a.mesureRechercheL();
		res2[1] = M2a.getRes();
			
		/*Mesures des recherches pour aleaT/L (voir méthode), répétitions fortes*/
		M2b.mesureRechercheT();
		res2[2] = M2b.getRes();
		M2b.mesureRechercheL();
		res2[3] = M2b.getRes();
			
		//Génération d'un fichier de sortie pour gnuplot
		M2a.output(res2);

		break;

	    case 3:
		//Nombre de courbes concret, égal à 4
		int nbCourbe3 = 4;
			
		double[][] res3 = new double[nbCourbe3][size0.length];
			
		//M2a -> Mesures pour les valeurs de répétition faibles
		Mesure M3 = new Mesure (size0, rep1a);

		/*Mesures des recherches pour aleaT (voir méthode), répétitions faibles*/
		M3.mesureMinimumSimpleT();
		res3[0] = M3.getRes();
		M3.mesureMinimumSimpleL();
		res3[1] = M3.getRes();
			
		/*Mesures des recherches pour aleaT/L (voir méthode), répétitions fortes*/
		M3.mesureMinimumTriT();
		res3[2] = M3.getRes();
		M3.mesureMinimumTriL();
		res3[3] = M3.getRes();
			
		//Génération d'un fichier de sortie pour gnuplot
		M3.output(res3);

		break;
		
	    case 4: /** Question 12*/
		int nbCourbe4 = 5;

		double[][] res4 = new double[nbCourbe4][size0.length];
		double param4 = 2.0;

		Mesure M4 = new Mesure(size0, rep0);

		M4.refLog(param4);
		res4[0] = M4.getRes();

		M4.refNpK(param4);
		res4[1] = M4.getRes();

		M4.refNlogn();
		res4[2] = M4.getRes();
		
		M4.refExp();
		res4[3] = M4.getRes();

		M4.refKpN(param4);
		res4[4] = M4.getRes();

		M4.output(res4);

		break;
		
		case 5: /** Question 14*/
		int nbCourbe5 = 5;

		double[][] res5 = new double[nbCourbe5][size0.length];
		double[] param5 = {2.0, 1.0, 0.5, 0.2, 0.1};

		Mesure M5 = new Mesure(size0, rep0);

		for (int i = 0; i < param5.length; i++) {
			M5.rapportLogNepsi(param5[i]);
			res5[i] = M5.getRes();
		}

		M5.output(res5);

		break;

		case 6:

		int nbCourbe6 = 8;

		double[][] res6 = new double[nbCourbe6][size0.length];
		double[] param6 = {5.0, 2.0, 1.5, 1.25, 1.1, 1.0};

		Mesure M6 = new Mesure(size0, rep0);

		for (int i = 0; i < param6.length; i++) {
			M6.rapportNpK2pN(param6[i]);
			res6[i] = M6.getRes();
		}

		M6.output(res6);

		break;
		
	    default:
		break;

	    }	    
	}
    }
}
