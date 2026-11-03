onmessage = function (e) {
    let dan = Number(e.data);
    let result = [];

    for (let i = 1; i <= 9; i++) {
        result.push(dan + " x " + i + " = " + (dan * i));
    }

    // "계산 중..."이 보이도록 1초 뒤에 결과 전달
    setTimeout(function () {
        postMessage(result);    // 결과를 메인 스레드로 보냄
    }, 1000);
};