import cv2

img = cv2.imread('./data/img1.jpg')

cv2.line(img,(100,100),(200,200),(0,0,255),2)
cv2.rectangle(img,(300,200),(400,300),(120,120,100),2)
cv2.circle(img,(300,200),25,(255,0,255),-1)
cv2.putText(img, "hello world", (500,200), cv2.FONT_HERSHEY_SIMPLEX, 1, (0,0,255), 2)

cv2.imshow('img',img)
cv2.waitKey(0)