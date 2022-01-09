'''
number - 현 노드의 주소
next - 현 노드의 다음 주소
prev - 현 노드의 전 주소

cmd = 	["D 2","C","U 3","C","D 4","C","U 2","Z","Z"]
'''
N=0
K=0
employees = []
delque = []
def INIT(n,k):
    global N,K,employees
    N=n
    K=k
    for i in range(0,n):
        employees.append({'number':i,'next':i+1,'prev':i-1,'die':False})
    employees[0]['prev']= 0
    employees[N-1]['next'] = N-1

def ACTION(command,number):
    global K,N,employees
    '''
    U X : 현재 선택된 행에서 X칸 위에 있는 행을 선택
    D X : 현재 선택된 행에서 X칸 아래
    C : 현재 행을 제거 후 아래 행 선택, 마지막이면 위 행
    Z : 가장 최근 삭제된 행을 복구
    '''
    if command == 'U':
        for num in range(0,number):
            K = employees[K]['prev']
    elif command == 'D':
        for num in range(0,number):
            K = employees[K]['next']
    elif command == 'C':
        delque.append(K) #현재 위치를 넣어
        employees[K]['die'] = True
        if employees[K]['number'] == employees[K]['next']: #마지막이면
            kprev = employees[K]['prev']
            employees[kprev]['next'] = employees[kprev]['number']  #이젠 얘가 마지막이다.
            K = employees[K]['prev']
        elif employees[K]['number'] == employees[K]['prev']: #맨 첫놈이면
            knext = employees[K]['next']
            employees[knext]['prev'] = employees[knext]['number'] #니가 대가리다
            K = employees[K]['next']
        else:  #마지막이 아냐 사잇값이면
            kprev = employees[K]['prev']
            knext = employees[K]['next']
            employees[kprev]['next'] = employees[knext]['number']
            employees[knext]['prev'] = employees[kprev]['number']  #둘을 이어주지
            K = employees[K]['next']   
    elif command == 'Z':   #복구
            zK = delque.pop()
            employees[zK]['die'] = False
            if employees[zK]['number'] == employees[zK]['next']: #마지막
                zKprev = employees[zK]['prev']
                employees[zKprev]['next'] = employees[zK]['number']
            elif employees[zK]['number'] == employees[zK]['prev'] : #처음
                zKnext = employees[zK]['next']
                employees[zKnext]['prev'] = employees[zK]['number']
            else:
                zKprev = employees[zK]['prev']
                zKnext = employees[zK]['next']
                employees[zKprev]['next'] = employees[zK]['number']
                employees[zKnext]['prev'] = employees[zK]['number']

def PRINT():
    global employees
    ret = ''
    for employee in employees:
        if employee['die'] == True:
            ret += 'X'
        else:
            ret += 'O'
    return ret

def solution(n, k, cmd):
    global N,K,employees
    answer = ''
    INIT(n,k)
    for tmp in cmd:
        tmp_split = tmp.split(' ')
        command = ''
        number = 0
        if len(tmp_split) == 2:
            command = tmp_split[0]
            number = int(tmp_split[1])
        else:
            command = tmp_split[0]
        ACTION(command,int(number))
    answer = PRINT()
    return answer

solution(8,2,["D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"])




