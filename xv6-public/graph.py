import matplotlib.pyplot

data = ""

with open("benchdump.txt") as f:
    data = f.read()

inp = data.strip().split("\n")
lines = []
for p in inp:
    list = p.split(" ")
    lines.append([int(list[0]), int(list[1]), int(list[2])])



no_of_processes = 9
bench_start_proc = 3
start_time=lines[0][0]


queue = []
for i in range(no_of_processes):
    queue.append([0])

pointer = 0

while pointer < len(lines):
    while start_time<lines[pointer][0]:
        for q in queue:
            q.append(q[-1])
        start_time+=1

    changes = {}
    while pointer < len(lines) and start_time==lines[pointer][0]:
        changes[lines[pointer][1]]=lines[pointer][2]
        pointer += 1

    start_time+=1

    for p in range(bench_start_proc,bench_start_proc+no_of_processes):
        if changes.get(p):
            queue[p-bench_start_proc].append(changes[p])
        else:
            queue[p-bench_start_proc].append(queue[p-bench_start_proc][-1])



matplotlib.pyplot.yticks([0,1,2,3,4])

c=bench_start_proc
matplotlib.pyplot.xlabel("Clock Ticks")
matplotlib.pyplot.ylabel("Queue")
for x in queue:
    matplotlib.pyplot.plot(x, linestyle='-', marker='o', label=str(c))
    c+=1
matplotlib.pyplot.legend()
matplotlib.pyplot.show()