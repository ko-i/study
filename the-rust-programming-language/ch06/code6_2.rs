enum Message {
    Quit,
    Move {x: i32, y: i32},
    Write(String),
    ChangeColor(i32, i32, i32),
}

struct QuitMessage;   // 空结构体

struct MoveMessage {
    x: i32,
    y: i32,
}

struct WriteMessage(String);   // 元组结构体
struct ChangeColorMessage(i32, i32, i32); // 元组结构体

impl Message {
    fn call(&self) {
        // 方法可以在这里定义
    }
}

fn main() {
    let m = Message::Write(String::from("hello"));
    m.call();
}