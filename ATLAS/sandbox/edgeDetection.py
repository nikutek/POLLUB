import cv2
import numpy as np
from numpy import int8

img = cv2.imread("./data/img1.jpg")

edge = cv2.Canny(img,100,200)
dilated = cv2.dilate(edge,np.ones((3,3), dtype=int8),iterations = 1)
eroded = cv2.erode(dilated,np.ones((3,3), dtype=int8),iterations = 1)

cv2.imshow("dilated",dilated)
cv2.imshow("edge",edge)
cv2.imshow("eroded",eroded)
cv2.waitKey(0)