
import cv2
import os

#read webcam
webcam = cv2.VideoCapture(0)


# show

while True:
    ret, frame = webcam.read()

    cv2.imshow('frame',frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
    


webcam.release()
cv2.destroyAllWindows()
