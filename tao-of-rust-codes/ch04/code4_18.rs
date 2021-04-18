use std::rc::Rc;

type NodePtr<T> = Option<Rc<Node<T>>>;

struct Node<T> {
    data: T,
    next: NodePtr<T>,
}

fn main() {
    let first = Rc::new(Node { data: 1, next: None});
    let second = Rc::new(Node { data: 2, next: None});

    first.next = Some(second.clone());
    second.next = Some(first.clone());
}