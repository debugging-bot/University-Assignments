onmessage = function(e){
    let a = e.data.a;
    let b = e.data.b;

    postMessage(a * b);   // 결과를 HTML 쪽으로 보냄
}