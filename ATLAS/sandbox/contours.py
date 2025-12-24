import cv2

img = cv2.imread("./data/birds2.jpg")
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
blured = cv2.GaussianBlur(gray, (5, 5), 0)

ret, thresh = cv2.threshold(blured, 127, 255, cv2.THRESH_BINARY_INV)

contours, hierarchy = cv2.findContours(thresh, cv2.RETR_TREE, cv2.CHAIN_APPROX_NONE)

for contour in contours:
    if cv2.contourArea(contour) > 50:
        x1,y1,w,h = cv2.boundingRect(contour)
        cv2.rectangle(img,(x1,y1),(x1+w,y1+h),(0,255,0),2)

cv2.imshow("img", img)
cv2.waitKey(0)