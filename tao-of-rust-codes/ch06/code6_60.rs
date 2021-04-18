struct Counter {
    count: usize,
}

impl Iterator for Counter {
    type Item = usize;

    fn next(&mut self) -> Option<usize> {
        self.count += 1;

        if self.count < 6 {
            Some(self.count)
        } else {
            None
        }
    }
}

fn main() {
    let mut counter = Counter {
        count: 0,
    };

    println!("{:?}", counter.next());
    println!("{:?}", counter.next());
    println!("{:?}", counter.next());
    println!("{:?}", counter.next());
    println!("{:?}", counter.next());
    println!("{:?}", counter.next());
}