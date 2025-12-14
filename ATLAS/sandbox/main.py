
import cv2
import os

img_path = os.path.join(".","data","img1.jpg");
vid_path = os.path.join(".","data","vid.mp4");

# read
img = cv2.imread(img_path);
vid = cv2.VideoCapture(vid_path);

#write
cv2.imwrite(os.path.join(".","data","cp_img1.jpg"), img);

# show
cv2.imshow("img",img);
cv2.waitKey(0);

ret = True;

while ret:
    ret, frame = vid.read();

    if(ret):
        cv2.imshow("frame", frame);
        cv2.waitKey(1);

cv2.destroyAllWindows();
vid.release();

