import random

def bubbleSort(frames):
    for i in range(len(frames)):
        flag = 0
        for j in range(len(frames)-i-1):
            if(frames[j][0] > frames[j+1][0]):
                temp = frames[j]
                frames[j] = frames[j+1]
                frames[j+1] = temp
                flag = 1
        if(flag == 0):
            break

def display (frames):
    for f in frames:
        print(f"SeqNo : {f[0]}  Data : {f[1]}")

def main():
    frames = []

    n = int(input("Enter no of frames : "))
    for i in range(n):
        print(f"Enter data of {i+1}th frame :")
        data = int(input())

        seqNo = random.randint(1, 10000)
        frames.append([seqNo, data])

    print("\n\nBefore Sorting : ")
    display(frames)

    bubbleSort(frames)

    print("\n\nAfter Sorting : ")
    display(frames)

if __name__ == "__main__":
    main()
