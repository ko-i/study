use std::fmt::Debug;

trait DoSomthing<T> {
    fn do_sth(&self, value: T);
}

impl<'a, T: Debug> DoSomthing<T> for &'a usize {
    fn do_sth(&self, value: T) {
        println!("{:?}", value);
    }
}

fn foo<'a>(b: Box<dyn DoSomthing<&'a usize>>) {
    let s: usize = 10;
    b.do_sth(&s);
}

fn main() {
    let x = Box::new(&2usize);
    foo(x);
}