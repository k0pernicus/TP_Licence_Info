import sys
import numpy as np
import cv2 as opencv

DATA = '../data/'
EXEMPLES = '../exemples/'

face_cascade = opencv.CascadeClassifier(DATA+"haarcascade_frontalface_default.xml")
eye_cascade = opencv.CascadeClassifier(DATA+"haarcascade_eye.xml")

if __name__ == "__main__":
	"""
	Programme principal
	"""

	img_path = EXEMPLES + sys.argv[1]

	img = opencv.imread(img_path)

	gray = opencv.cvtColor(img, opencv.COLOR_BGR2GRAY)

	faces = face_cascade.detectMultiScale(gray, 1.3, 5)

	for (x,y,w,h) in faces:
	    opencv.rectangle(img,(x,y),(x+w,y+h),(255,0,0),2)
	    roi_gray = gray[y:y+h, x:x+w]
	    roi_color = img[y:y+h, x:x+w]
	    eyes = eye_cascade.detectMultiScale(roi_gray)
	    for (ex,ey,ew,eh) in eyes:
	        opencv.rectangle(roi_color,(ex,ey),(ex+ew,ey+eh),(0,255,0),2)

	opencv.imshow('img',img)
	opencv.waitKey(0)
	opencv.destroyAllWindows()