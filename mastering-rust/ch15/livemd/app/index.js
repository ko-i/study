import('./livemd').then((livemd) => {
    var editor = document.getElementById("editor");
    var preview = document.getElementById("preview");

    var markdownToHtml = function() {
        var markdownText = editor.value;
        html = livemd.parse(markdownText);
        preview.innerHTML = html;
    };

    editor.addEventListener('input', markdownToHtml);
    markdownToHtml();
}).catch(console.error);