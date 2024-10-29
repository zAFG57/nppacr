from PIL import Image
import numpy

im = Image.open('original.png')
pix = im.load()

xmax, ymax = im.size

points = {}


for x in range(xmax):
    for y in range(ymax):
        if(pix[x,y] != (255,255,255,255)):
            points[(x,y)] = pix[x,y]




newImage = []
for y in range(ymax):
    newImage.append([])
    for x in range(xmax):
        newImage[y].append((255,255,255,255))
        if ((x,y) not in points):
            newImage[y][x] = (255,255,255,255)
        else:
            newImage[y][x] = points[(x,y)]



arr = numpy.asarray(newImage)



img = Image.fromarray(arr,"RGBA")
img.save('modify.png')


arr2 = numpy.array(im)


xmax, ymax = img.size

points = {}

for x in range(xmax):
    for y in range(ymax):
            a = pix[x,y]
            b = arr[y,x]
            for i in range(len(a)):
                if (a[i] != b[i]):
                    print(a,b)