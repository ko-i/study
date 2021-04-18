pub struct Queue {
    older: Vec<char>,
    younger: Vec<char>,
}

impl Queue {
    pub fn new() -> Queue {
        Queue {
            older: Vec::new(),
            younger: Vec::new()
        }
    }

    pub fn push(&mut self, c: char) {
        self.younger.push(c);
    }

    pub fn pop(&mut self) -> Option<char> {
        if self.older.is_empty() {
            if self.younger.is_empty() {
                return None;
            }

            use std::mem::swap;
            swap(&mut self.older, &mut self.younger);
            self.older.reverse();
        }

        self.older.pop()
    }

    pub fn is_empty(&self) -> bool {
        self.older.is_empty() && self.younger.is_empty()
    }

    pub fn split(self) -> (Vec<char>, Vec<char>) {
        (self.older, self.younger)
    }
}

fn main() {
    let mut q = Queue {
        older: Vec::new(),
        younger: Vec::new(),
    };

    q.push('0');
    q.push('1');
    println!("{:?}", q.pop());

    q.push('e');
    println!("{:?}", q.pop());
    println!("{:?}", q.pop());
    println!("{:?}", q.pop());

    println!("{:?}", q.is_empty());
    q.push('1');
    println!("{:?}", q.is_empty());

    q.pop();

    q.push('q');
    q.push('d');
    println!("{:?}", q.pop());
    q.push('x');

    let (older, younger) = q.split();
    println!("{:?}", older);
    println!("{:?}", younger);
}