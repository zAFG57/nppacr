from random import *

def dist(a,b):
    dist = 0
    for i in range(len(a)):
        dist += (a[i]-b[i])*(a[i]-b[i])
    return dist

def findnpp(point,espace,nb):
    """retrouve les n point les plus proches"""
    points = []
    distes = []
    maxDist = -1
    indicMaxDist = -1
    for i in espace.keys():
        if (len(points)<nb):                    # choix des nb point
            points.append(i)
            diste = dist(point,i)
            distes.append(diste)
            if (diste>maxDist):
                maxDist = diste
                indicMaxDist = len(points)-1
        else:                                  # reduit à partir du calcul de la distance
            diste = dist(point,i)
            if (diste<maxDist):
                points.pop(indicMaxDist)
                distes.pop(indicMaxDist)
                points.append(i)
                distes.append(diste)
                maxDist = max(distes)
                indicMaxDist = distes.index(maxDist)
    return points, distes

def getColorOfPoints(points,espace):
    colors = []
    for i in points:
        colors.append(espace[i])
    return colors

def calcColorAvrage(colors,dist):
    r = 0
    g = 0
    b = 0
    tt = 0
    for i in range(len(colors)):
        tt += 1/dist[i]
        r += colors[i][0]/dist[i]
        g += colors[i][1]/dist[i]
        b += colors[i][2]/dist[i]
    r = round(r/tt)
    g = round(g/tt)
    b = round(b/tt)
    return (r,g,b)

def getRandomPoint(espace,xmax,ymax):
    x = randint(0,xmax)
    y = randint(0,ymax)
    while (x,y) in espace:
        x = randint(0,xmax)
        y = randint(0,ymax)
    return (x,y)