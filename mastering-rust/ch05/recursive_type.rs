struct Node {
    data: u32,
    next: Option<Box<Node>>,
}

fn main() {
    let a = Node {
        data: 33,
        next: None
    };
}