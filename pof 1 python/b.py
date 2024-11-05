from PIL import Image
import numpy
from functionB import *


nbPts = 1542
n=5

im = Image.open('content/original.png')

arr = numpy.array(im)
points = {}
ymax  = len(arr)
xmax = len(arr[0])

for y in range(ymax):
    for x in range(xmax):
        if list(arr[y,x]) != [255,255,255,255]:
            points[(x,y)] = (arr[y,x][0],arr[y,x][1],arr[y,x][2])


# ici on peut inférer
while nbPts != 0:
    lePts = getRandomPoint(points,xmax,ymax)
    pts,distes = findnpp(lePts,points,n)
    colors = getColorOfPoints(pts,points)
    color = calcColorAvrage(colors,distes)
    points[lePts] = color
    nbPts -= 1
    if nbPts%100 == 0: print(100 - 100*nbPts/1500)

im = Image.new(mode="RGB", size=(xmax, ymax))

for y in range(ymax):
    for x in range(xmax):
        if ((x,y) in points):
            im.putpixel((x, y), points[(x,y)])
        else:
            im.putpixel((x, y), (0, 0, 0))


im.save("content/modify.png")