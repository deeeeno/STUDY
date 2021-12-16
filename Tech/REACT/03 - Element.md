# REACT - 03.Element
element는 React 앱의 가장 작은 단위이고, 화면에 표시할 내용을 기술한다.
```
const element = <h1>Hello, world</h1>;
ReactDOM.render(element, document.getElementById('root'));
```
일반적으로 React로 구현된 element는 하나의 루트 DOM을 가진다. 보통 root로 칭함. React 엘리먼트를 렌더링 하는 함수는 **ReactDOM.render()**

React 엘리먼트는 constant한 객체이다. 그래서 생성 이후엔 속성을 변경할 수 없다. 즉, 엘리먼트는 하나의 프레임 같은 느낌인 것이다!!
다시 render를 하면 업데이트가 되는데, 이 때 전부 다 뒤집어 엎는 것이 아닌 이전 DOM과 비교해서 변한 부분만 업데이트를 한다.

```
function tick() {
  const element = (
    <div>
      <h1>Hello, world!</h1>
      <h2>It is {new Date().toLocaleTimeString()}.</h2>
    </div>
  );
  ReactDOM.render(element, document.getElementById('root'));
}

setInterval(tick, 1000);
```
