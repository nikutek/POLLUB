
import os
import cv2

img = cv2.imread('data/img1.jpg')
cv2.imshow('img',img)
print( img.shape)

resized = cv2.resize(img, (200, 200) )
print(resized.shape)
cv2.imshow('resized',resized)

cv2.waitKey(0)
cv2.destroyAllWindows()

