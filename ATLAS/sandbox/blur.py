import cv2

img = cv2.imread("./data/img1.jpg")
# blured = cv2.GaussianBlur(img,(5,5),0)
# blured = cv2.blur(img,(9,9))
blured = cv2.medianBlur(img,5)
cv2.imshow('img',img)
cv2.imshow('blurred',blured)
cv2.waitKey(0)
cv2.destroyAllWindows()