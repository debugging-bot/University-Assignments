function multiply() {
    let num1 = document.getElementById("num1");
    let div = document.getElementById("div");

    div.innerHTML = "계산 중...";

    let addWorker = new Worker("worker.js");     // 워커 생성

    addWorker.onmessage = function (e) {         // 워커가 보낸 결과 받기
        div.innerHTML = e.data.join("<br>");
        addWorker.terminate();
    };

    addWorker.postMessage(num1.value);           // 워커에 숫자 전달
}