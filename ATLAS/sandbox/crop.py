import cv2

img = cv2.imread('data/img1.jpg')
cv2.imshow('img',img)
print(img.shape)
#     [top:bottom, left:right]
cropped = img[20:500,200:550]


cv2.imshow('cropped',cropped)
cv2.waitKey(0)
cv2.destroyAllWindows()
