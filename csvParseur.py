from copy import deepcopy

NB_JOUR_AVANT = 4
NB_JOUR_APRES = 3
FinalFile = ""
idxHight = 1
idxLow = 2

csvFile = "./content/BTCUSDT_1h.csv"
savingFile= "./content/data.custom"

#########################
#                       #
#       fonction        #
#                       #
#########################

def toFloat(f):
    return float(f.replace("'",'').replace('"',""))

def saveNewRow(jours):
    global FinalFile
    a = deepcopy(jours)
    maxN, minN = findMaxAndMin(a)
    row = ""
    for jour in range(NB_JOUR_AVANT):
        j = a[jour]
        row += str(normelized(maxN,minN,toFloat(j[idxHight]))) + " " + str(normelized(maxN,minN,toFloat(j[idxLow]))) + " "
    row += str(getValue(a,maxN,minN)) + " "
    FinalFile += row

def normelized(maxN,minN,val):
    return (val-minN) / (maxN-minN)

def findMaxAndMin(jours):
    maxN = -1
    minN = -1
    for i in range(NB_JOUR_AVANT):
        if (maxN == -1):
            maxN = toFloat(jours[i][idxHight])
            minN = toFloat(jours[i][idxLow])
        if (maxN<toFloat(jours[i][idxHight])):
            maxN = toFloat(jours[i][idxHight])
        if (minN > toFloat(jours[i][idxLow])):
            minN = toFloat(jours[i][idxLow])
    return maxN,minN

def getValue(jours,maxN,minN):
    avg=0
    for a in range(NB_JOUR_AVANT,NB_JOUR_AVANT+NB_JOUR_APRES):
        i = jours[a]
        avg += (normelized(maxN,minN,toFloat(i[idxHight])) + normelized(maxN,minN,toFloat(i[idxLow])))/2
    return avg/NB_JOUR_APRES

#########################
#                       #
#       programe        #
#                       #
#########################


f = open(csvFile,"r")
csv = f.read()
f.close()

csv = csv.split("\n")
csv.pop(0)
csv.reverse()


jours = []

for j in csv:
    if (len(jours)>=NB_JOUR_AVANT*NB_JOUR_APRES):
        jours.pop(0)
    jours.append(j.split(","))
    if (len(jours)>=NB_JOUR_AVANT*NB_JOUR_APRES):
        saveNewRow(jours)

f = open(savingFile,'w')
f.write(FinalFile)
f.close()