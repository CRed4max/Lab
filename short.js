var welcome = "Welcome ";

var targetNode = document.querySelector(".sc-cQFLBn.gXNFCv");

var config = { attributes: false, childList: true, subtree: true };

var callback = function (mutationsList, observer) {
  for (let mutation of mutationsList) {
    if (mutation.addedNodes.length > 0) {
      if (
        mutation.addedNodes[0] &&
        mutation.addedNodes[0].innerText &&
        mutation.addedNodes[0].classList.value == "sc-hORach jBrJiT"
      ) {
        if (mutation.addedNodes[0].innerText.includes("joined.")) {
          var pressEnter = new KeyboardEvent("keypress", {
            bubbles: true,
            cancelable: true,
            keyCode: 13,
          });

          var element = document.querySelector("textarea");
          element.focus();

          var textToSend = mutation.addedNodes[0].innerText
            .split("joined")[0]
            .trim()
            .split("]")[1]
            .trim()
            .split(" ")[0]
            .trim();
          textToSend = welcome + textToSend + "\n";

          document.execCommand("insertText", false, textToSend);
          setTimeout(() => {
            element.dispatchEvent(pressEnter);
          }, 3000);
        }
      }
    }
  }
};

var observer = new MutationObserver(callback);

observer.observe(targetNode, config);
