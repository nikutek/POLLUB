import cv2

img = cv2.imread('./data/img1.jpg')
gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

thresh = cv2.adaptiveThreshold(gray, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 11, 2)
cv2.imshow('img',img)

cv2.imshow('gray',thresh)
cv2.imshow('img',img)
cv2.waitKey(0)
cv2.destroyAllWindows()

for i in range(0,255):
    ret, thresh = cv2.threshold(gray,i,255,cv2.THRESH_BINARY)
    cv2.imshow('thresh',thresh)
    cv2.waitKey(50)