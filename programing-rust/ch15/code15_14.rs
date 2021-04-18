struct Flaky(bool);

impl Iterator for Flaky {
    type Item = &'static str;

    fn next(&mut self) -> Option<Self::Item> {
        if self.0 {
            self.0 = false;
            Some("totally the last item")
        } else {
            self.0 = true;

            None
        }
    }
}

fn main() {
    let mut flaky = Flaky(true);

    println!("{:?}", flaky.next());
    println!("{:?}", flaky.next());
    println!("{:?}", flaky.next());
    println!("{:?}", flaky.next());

    let mut not_flaky = Flaky(true).fuse();
    println!("{:?}", not_flaky.next());
    println!("{:?}", not_flaky.next());
    println!("{:?}", not_flaky.next());
}