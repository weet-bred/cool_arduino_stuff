#This script opens a laptop webcam, does motion detection, and 
#sends serial signals to a connected Arduino with 2 servos attached to point whatever is on the servos at whatever is moving. some calibration is required.
#Last updated October of 2018 by Peter Engels



# importing OpenCV and Pandas library 
import cv2, pandas, serial, time
import numpy as np

#arduino movement command functions
def left(ser):
    ser.write(b'1')
def right(ser):
    ser.write(b'2')
def up(ser):
    ser.write(b'3')
def down(ser):
    ser.write(b'4')
def reset(ser):
    ser.write(b'5')
def up90(ser):
    ser.write(b'6')
def hzero(ser):
    ser.write(b'7')
def vzero(ser):
    ser.write(b'8')
def h90(ser):
    ser.write(b'9')
def fastLeft(ser):
    ser.write(b'11')
def fastRight(ser):
    ser.write(b'12')
def fastUp(ser):
    ser.write(b'13')
def fastDown(ser):
    ser.write(b'14')

def slowLeft(ser):
    ser.write(b'15')
def slowRight(ser):
    ser.write(b'16')
def slowUp(ser):
    ser.write(b'17')
def slowDown(ser):
    ser.write(b'18')


#initialize min and max of arduino
def setup(ser):
    #put them back to 0
    reset(ser)
    #put the vertical one at 90
    up90(ser);
    h90(ser);

    print("Press 'x' when laser is at right edge of screen. Press 'z' to move it further")
    for a in range(90, 0, -5):
        print(a)
        right(ser)
        x = input("'x' to quit: ")
        if x.find('x') != -1:
            h90(ser)
            rightMost = a
            ser.reset_input_buffer()
            break

    print("Press 'x' when laser is at left edge of screen. Press 'z' to move it further")
    for a in range(90, 180, 5):
        print(a)
        left(ser)
        x = input("'x' to quit: ")
        if x.find('x') != -1:
            h90(ser)
            leftMost = a
            ser.reset_input_buffer()
            break
                
    print("Press 'x' when laser is at top edge of screen")
    for a in range(90, 180, 5):
        print(a)
        up(ser)
        x = input("'x' to quit: ")
        if x.find('x') != -1:
            up90(ser)
            topMost = a
            ser.reset_input_buffer()
            break

    print("Press 'x' when laser is at bottom edge of screen")
    for a in range(90, 180, 5):
        print(a)
        up(ser)
        x = input("'x' to quit: ")
        if x.find('x') != -1:
            up90(ser)
            bottomMost = a
            ser.reset_input_buffer()
            break

    print ("rightMost: " + str(rightMost) + " leftMost: " + str(leftMost) + " topMost: " + str(topMost) + " bottomMost: " + str(bottomMost))
    return [rightMost, leftMost, topMost, bottomMost]

def aimServo(extremes, x, y, currentx, currenty):
    rightMost = extremes[0]
    leftMost = extremes[1]
    topMost = extremes[2]
    bottomMost = extremes[3]

    #width of screen = 640
    #height of screen = 480
    #so this bit says "the target falls in x spot between 0 and 640
    #"the target falls in y spot in between 0 and 480
    #so now we need to scale it to be in x spot between rightmost and leftMost
    #and we need to scale 9it to be in y spot between topMost and bottomMost
    #targetx = int((x - rightMost) / )
    targetx = int((x * (leftMost - rightMost) / 640) + rightMost)
    targety = int((y * (topMost - bottomMost) / 480) + bottomMost)
    #targety = int(((y * (topMost - bottomMost)) / 480) + bottomMost)
    print("bottommost -  topmost = " + str((topMost - bottomMost) / 480 + topMost))
    print("leftmost - rightmost = " + str(leftMost - rightMost))
    print("target: " + str(targetx) + ' ' + str(targety))
    print("current: " + str(currentx) + ' ' + str(currenty))
    
  #  while (currentx != targetx and currenty != targety):
    if (currentx - targetx) > 50 or (currenty - targety) > 50:
        pass
    if (currentx - targetx) < -50 or (currenty - targety) < -50:
        pass
    elif (currentx - targetx) >= 15:
        if currentx >= 15:
            fastLeft(ser)
            currentx -= 15
    elif (currentx - targetx) <= -15:
        if currentx <= 165:
            fastRight(ser)
            currentx += 15
    elif (currentx - targetx) >= 5:
        if currentx >= 5:
           left(ser)
           currentx -= 5
    elif (currentx - targetx) <= -5:
        if currentx <= 175:
            right(ser)
            currentx += 5
   # elif (currentx - targetx) >= 1:
   #     if currentx >= 1:
   #         slowRight(ser)
   #         currentx -= 1
   # elif (currentx - targetx) <= -1:
   #     if currentx <= 179:
   #         slowLeft(ser)
   #         currentx += 1

    if (currenty - targety) >= 15:
        if currenty >= 15:
            fastUp(ser)
            currenty -= 15
    elif (currenty - targety) <= -15:
        if currenty <= 165:
            fastDown(ser)
            currenty += 15
    elif (currenty - targety) <= -5:
        if currenty <= 175:
            down(ser)
            currenty += 5
    elif (currenty - targety) >= 5:
        if currenty >= 5:
            up(ser)
            currenty -= 5
   # elif (currenty - targety) <= -1:
   #     if currenty <= 179:
   #         slowUp(ser)
   #         currenty += 1
   # elif (currenty - targety) >= 1:
   #     if currenty >= 1:
   #         slowDown(ser)
   #         currenty -= 1

    ser.reset_input_buffer()
    return [currentx, currenty]
    time.sleep(.5)

    

# Assigning our static_back to None 
static_back = None
 
#opening channel to talk to arduino
ser = serial.Serial('/dev/ttyACM0') 
  
  
# Initializing DataFrame, one column is start  
# time and other column is end time 
df = pandas.DataFrame(columns = ["Start", "End"]) 
  
# Capturing video 
video = cv2.VideoCapture(0) 
time.sleep(2)

extremes = setup(ser)

h90(ser)
time.sleep(.2)
up90(ser)
time.sleep(.4)

currentx = 90
currenty = 90
  
# Infinite while loop to treat stack of image as video 
while True: 
    # Reading frame(image) from video 
    check, frame = video.read() 
  
  
    # Converting color image to gray_scale image 
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY) 
  
    # Converting gray scale image to GaussianBlur  
    # so that change can be find easily 
    gray = cv2.GaussianBlur(gray, (21, 21), 0) 
  
    # In first iteration we assign the value  
    # of static_back to our first frame 
    if static_back is None: 
        static_back = gray 
        continue
  
    # Difference between static background  
    # and current frame(which is GaussianBlur) 
    diff_frame = cv2.absdiff(static_back, gray) 
  
    # If change in between static background and 
    # current frame is greater than 30 it will show white color(255) 
    thresh_frame = cv2.threshold(diff_frame, 50, 255, cv2.THRESH_BINARY)[1] 
    thresh_frame = cv2.dilate(thresh_frame, None, iterations = 2) 
  
    # Finding contour of moving object 
    (_, cnts, _) = cv2.findContours(thresh_frame.copy(),  
                       cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE) 
  
    maxCnt = 100000
    for contour in cnts: 
        if cv2.contourArea(contour) < 10000: 
            continue
  
        (x, y, w, h) = cv2.boundingRect(contour) 
        # making green rectangle arround the moving object 
        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 10) 
        #print(str(w) + ' ' + str(h))
        hmid = (w / 2) + x
        vmid = (h / 2) + y
        print("h and v" + str(hmid) + ' ' + str(vmid))
        currentCoords = aimServo(extremes, hmid, vmid, currentx, currenty)
        currentx = currentCoords[0]
        currenty = currentCoords[1]
  
  
    # Displaying image in gray_scale 
    cv2.imshow("Gray Frame", gray) 
  
    # Displaying the difference in currentframe to 
    # the staticframe(very first_frame) 
    cv2.imshow("Difference Frame", diff_frame) 
  
    # Displaying the black and white image in which if 
    # intencity difference greater than 30 it will appear white 
    cv2.imshow("Threshold Frame", thresh_frame) 
  
    # Displaying color frame with contour of motion of object 
    cv2.imshow("Color Frame", frame) 
  
    key = cv2.waitKey(1) 
    # if q entered whole process will stop 
    if key == ord('q'): 
        break
  
  
video.release() 
  
# Destroying all the windows 
cv2.destroyAllWindows() 
