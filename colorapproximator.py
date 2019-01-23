import sys, pyautogui, time, pygame
from PIL import ImageGrab

import imports
from   imports import getColor

# Finds average pixel color in a box of pixels
# while True:
myfile = open('database.txt', 'a')
for x in range(0,20):
  px=ImageGrab.grab().load()
  colorlist = []
  for y in range(953,1025,3):
    for x in range(668,746,3):
      color=px[x,y]
      colorlist.append(color)
      print(color)
  sumx = 0
  sumy = 0
  sumz = 0
  length = len(colorlist)
  for coord in colorlist:
    sumx += coord[0]
    sumy += coord[1]
    sumz += coord[2]
  print("Average color:", sumx/length, sumy/length, sumz/length)
  myfile.write("\n" + str(sumx/length) + ", " + str(sumy/length) + ", " + str(sumz/length))
myfile.close()

# get color of pixel and location of pixel
# while True:
#   px=ImageGrab.grab().load()
#   currentMouseX, currentMouseY = pyautogui.position()
#   for y in range(currentMouseY,currentMouseY+1,1):
#     for x in range(currentMouseX,currentMouseX+1,1):
#       #print(x,y) #error check if mouse out of range
#       color=px[x,y]
#       print(color, (currentMouseX, currentMouseY))
