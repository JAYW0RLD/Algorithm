# [Gold IV] 공격 - 1430 

[문제 링크](https://www.acmicpc.net/problem/1430) 

### 성능 요약

메모리: 2208 KB, 시간: 4 ms

### 분류

수학, 그래프 이론, 그래프 탐색, 기하학, 너비 우선 탐색, 최단 경로

### 제출 일자

2025년 6월 30일 21:32:06

### 문제 설명

<p>다솜이는 누구나 쉽게 게임을 만들 수 있도록 하기 위해 Microsoft에서 출시한 XNA Game Studio Express를 가지고 게임을 만들었다.</p>

<p>다솜이의 게임은 적의 공격에 대비해서 도시를 방어하는 게임이다. 도시에는 탑이 N개가 있다. 각각의 탑은 X-Y좌표 평면위에 존재한다. 또, 탑은 맨 처음에 D의 에너지를 가지고 있고, 탑의 사정거리는 R이다.</p>

<p>탑 주변에 적이 나타나면, 탑은 적을 다음과 같은 방법으로 공격할 수 있다.</p>

<p>일단, 탑은 자신의 에너지를 재분배할 수 있다. 만약 서로 다른 두 탑의 거리가 R보다 작거나 같다면, 둘 중에 한 탑은 다른 탑에게 에너지를 자기가 가지고 있는 한도내에서 자유롭게 전송할 수 있다. 하지만, 에너지를 전송할 때는, 절반을 잃는다. (탑 1이 탑 2에게 에너지를 10 전송하면, 탑 1은 에너지를 10을 잃고, 탑 2는 에너지를 5 얻는다.)</p>

<p>탑이 적을 공격할 때는, 적과 탑의 거리가 R보다 작거나 같아야한다. 탑에서 적을 공격할 때는, 자신의 모든 에너지를 적을 공격하는데 쓴다. 이때 적이 받는 데미지는 에너지의 양과 같다.</p>

<p>적이 받을 수 있는 에너지의 최댓값을 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 탑의 개수 N, 사정 거리 R, 초기 에너지 D, 적의 X좌표 X, 적의 Y좌표 Y가 주어진다. 둘째 줄부터는 탑의 위치가 한 줄에 하나씩 X좌표 Y좌표 순으로 주어진다. N은 50보다 작거나 같은 자연수이고, R은 500보다 작거나 같은 자연수, D는 100보다 작거나 같은 자연수이다. 모든 X좌표와 Y좌표는 1,000보다 작거나 같은 음이 아닌 정수이다. 탑의 위치가 같은 경우는 없고, 적과 탑의 위치가 같은 경우도 입력으로 주어지지 않는다.</p>

### 출력 

 <p>첫째 줄에 적이 받는 데미지의 최댓값을 출력한다. 절대/상대 오차는 10<sup>-2</sup>까지 허용한다.</p>

