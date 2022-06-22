import csv
import sys

def sortbyone (li,spot) :
    return(sorted(li, key = lambda x: x[spot - 1]))

def sortbytwo (li,spot, spot2) :
    return(sorted(li, key = lambda x: (x[spot - 1], x[spot2 - 1])))

def averagewait (list) :
    res = 0
    count = 0
    for row in list :
        res += row[1]
        count += 1
    return res/count

def averageturnaround(list) :
    res = 0
    count = 0
    for row in list :
        res += row[2]
        count += 1
    return res/count

if(len(sys.argv) != 3) :
    print(sys.argv)
    print("Not enough or too many arguements")
    exit()

filename = sys.argv[1]
quantum = int(sys.argv[2])

columnName = []
rows = []

with open(filename, 'r') as csv_file:
    reader = csv.reader(csv_file)

    fields = next(reader)

    for row in reader:
        rows.append(row)

for i, row in enumerate(rows) :
    rows[i] = [ int(x) for x in row ]


print("----------------- FCFS -----------------")

rowsFCFS = sortbytwo(rows,2,1)
time = 0
chartFCFS = []
ganttchartFCFS = []
for row in rowsFCFS:
    arrivaltime = int(row[1])
    bursttime = int(row[2])
    if (time == 0 & arrivaltime != 0) :
        ganttchartFCFS.append([0,'IDLE',arrivaltime])
        time += arrivaltime
    if (arrivaltime > time):
        ganttchartFCFS.append([time,'IDLE',time + (arrivaltime-time)])
        time += arrivaltime - time
    time += bursttime
    competiontime = time
    turnaroundtime = competiontime - arrivaltime
    waitingtime = turnaroundtime - bursttime
    chartFCFS.append([int(row[0]),waitingtime,turnaroundtime])
    ganttchartFCFS.append([time-bursttime, row[0], time])

print("Process ID | Waiting Time | Turnaround Time")
chartFCFS = sortbyone(chartFCFS,1)
for row in chartFCFS :
    print("    "+str(row[0])+"      |      "+str(row[1])+"       |        "+str(row[2]))
print("Gantt Chart is:")
for row in ganttchartFCFS:
    print("[  "+str(row[0])+"  ]--  "+str(row[1])+"  --[  "+str(row[2])+"  ]")
print("Average wait time: " + str(averagewait(chartFCFS)))
print("Average turnaround time: "+str(averageturnaround(chartFCFS)))
throughput = len(rowsFCFS) / ((ganttchartFCFS[len(ganttchartFCFS)-1][2]) - (rowsFCFS[0][1]))
print("Throughput: "+str(throughput) + "\n")


print("----------------- PBS -----------------")

rowsPBS = rows
rowsPBS = sortbytwo(rowsPBS,2,4)
time = 0
chartPBS = []
ganttchartPBS = []

for row in rowsPBS:
    arrivaltime = int(row[1])
    bursttime = int(row[2])
    if (time == 0 & arrivaltime != 0) :
        ganttchartPBS.append([0,'IDLE',arrivaltime])
        time += arrivaltime
    if (arrivaltime > time):
        ganttchartPBS.append([time,'IDLE',time + (arrivaltime-time)])
        time += arrivaltime - time
    time += bursttime
    competiontime = time
    turnaroundtime = competiontime - arrivaltime
    waitingtime = turnaroundtime - bursttime
    chartPBS.append([int(row[0]),waitingtime,turnaroundtime])
    ganttchartPBS.append([time-bursttime, row[0], time])

print("Process ID | Waiting Time | Turnaround Time")
chartPBS = sortbyone(chartPBS,1)
for row in chartPBS :
    print("    "+str(row[0])+"      |      "+str(row[1])+"       |        "+str(row[2]))
print("Gantt Chart is:")
for row in ganttchartPBS:
    print("[  "+str(row[0])+"  ]--  "+str(row[1])+"  --[  "+str(row[2])+"  ]")
print("Average wait time: " + str(averagewait(chartPBS)))
print("Average turnaround time: "+str(averageturnaround(chartPBS)))
throughput = len(rowsPBS) / ((ganttchartPBS[len(ganttchartPBS)-1][2]) - (rowsPBS[0][1]))
print("Throughput: "+str(throughput) + "\n")


print("----------------- Round Robin -----------------")

rowsRR = rows
for row in rowsRR :
    row.append(0)
    row.append(0)
rowsRR = sortbytwo(rowsRR, 2, 1)
time = 0;
chartRR = []
ganttchartRR = []
queue = []

def check(list) :
    count = len(list)
    for row in list :
        if (row[2] == 0) :
            count -=1
    return count

def contains(list, item) :
    for i in list :
        if (i==item[0]) :
            return 1
    return 0

def addtoqueue(time, cur) :
    for item in rowsRR :
        if (item[1] <= time and contains(queue,item) == 0 and item[0] != cur and item[2] != 0) :
            queue.append(item[0])

def nextAT() :
    nextat = 100000000000
    for row in rowsRR :
        if (row[1] < nextat and row[2] != 0) :
            nextat = row[1]
    return nextat

while (check(rowsRR) != 0) :
    if (time == 0) :
        for row in rowsRR :
            if (row[1] == 0) :
                queue.append(row[0])
        if (len(queue) == 0) :
            ganttchartRR.append([time,'IDLE',rowsRR[0][1]])
            time += rowsRR[0][1]
            for row in rowsRR :
                if (row[1] == time) :
                    queue.append(row[0])
    if (len(queue) == 0 ) :
        num = nextAT()
        ganttchartRR.append([time,'IDLE',num])
        time = num
        addtoqueue(time, -1)
    for i in range(0,len(queue)) :
        id = queue.pop(0)
        for row in rowsRR :
            if (row[0] == id) :
                if (row[2] <= quantum) :
                    ganttchartRR.append([time,id,time+row[2]])
                    time += row[2]
                    row[4] += row[2]
                    row[2] = 0
                    row[5] = time
                    addtoqueue(time,id)
                else :
                    ganttchartRR.append([time,id,time+quantum])
                    row[4] += quantum
                    time += quantum
                    row[2] -= quantum
                    addtoqueue(time,id)
                    queue.append(id)

print("Process ID | Waiting Time | Turnaround Time")
sorted = sortbyone(rowsRR,1)
for row in sorted :
    id = row[0]
    arrivaltime = row[1]
    bursttime = row[4]
    competiontime = row[5]
    turnaroundtime = competiontime - arrivaltime
    waitingtime = turnaroundtime - bursttime
    chartRR.append([id,waitingtime,turnaroundtime])
for row in chartRR :
    print("    "+str(row[0])+"      |      "+str(row[1])+"       |        "+str(row[2]))

print("Gantt Chart is:")
for row in ganttchartRR:
    print("[  "+str(row[0])+"  ]--  "+str(row[1])+"  --[  "+str(row[2])+"  ]")

print("Average wait time: " + str(averagewait(chartRR)))
print("Average turnaround time: "+str(averageturnaround(chartRR)))
throughput = len(rowsRR) / ((ganttchartRR[len(ganttchartRR)-1][2]) - (rowsRR[0][1]))
print("Throughput: "+str(throughput) + "\n")