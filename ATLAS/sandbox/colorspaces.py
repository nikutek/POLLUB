import cv2

img = cv2.imread('data/img1.jpg')
img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

cv2.imshow('img',img)
cv2.imshow('imgRGB',img_rgb)
cv2.imshow('imgGray',img_gray)
cv2.waitKey(0)

cv2.cvtColor(img, cv2.COLOR_BGR2RGB)