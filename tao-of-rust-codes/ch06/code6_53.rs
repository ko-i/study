use std::fmt::Debug;

trait DoSomething<T> {
    fn do_sth(&self, value: T);
}

impl<'a, T: Debug> DoSomething<T> for &'a usize {
    fn do_sth(&self, value: T) {
        println!("{:?}", value);
    }
}

fn bar(b: Box<dyn for<'f> DoSomething<&'f usize>>) {
    let s: usize = 10;
    b.do_sth(&s);
}

fn main() {
    let x = Box::new(&2usize);
    bar(x);
}