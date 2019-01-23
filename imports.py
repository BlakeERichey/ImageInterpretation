import sys, pyautogui, time, pygame
from PIL import ImageGrab

def getColor(surface, pos1, pos2):
  color1 = False
  color2 = False
  if pos2 == None:
    for y in range(pos1[1],pos1[1]+1,1):
      for x in range(pos1[0],pos1[0]+1,1):
        color1=surface[x,y]
        print(color1, (x,y))
    return color1
  elif pos2 != None:
    for y in range(pos2[1],pos2[1]+1,1):
      for x in range(pos2[0],pos2[0]+1,1):
        color2=surface[x,y]
    return color1, color2