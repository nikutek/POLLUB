import cv2

webcam = cv2.VideoCapture(0)

while True:
    ret, img = webcam.read()


    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    blured = cv2.GaussianBlur(gray,(5,5),0)
    thresh = cv2.adaptiveThreshold(blured,
                                   255,
                                   cv2.ADAPTIVE_THRESH_GAUSSIAN_C,
                                   cv2.THRESH_BINARY,
                                   199,
                                   20)

    contours, hierarchy = cv2.findContours(thresh,
                                           cv2.RETR_TREE,

                                           cv2.CHAIN_APPROX_NONE)
    for contour in contours:
        area = cv2.contourArea(contour)
        x1,y1,w,h = cv2.boundingRect(contour)
        if(cv2.contourArea(contour) > 500):
            cv2.rectangle(img,(x1,y1),(x1+w,y1+h),(0,255,0),3)
            print(area)

    cv2.imshow("img", img)
    cv2.imshow("thresh", thresh)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break


cv2.destroyAllWindows()