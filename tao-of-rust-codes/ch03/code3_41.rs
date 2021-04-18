use std::fmt::Debug;

pub trait Fly {
    fn fly(&self) -> bool;
}

#[derive(Debug)]
struct Duck;

#[derive(Debug)]
struct Pig;

impl Fly for Duck {
    fn fly(&self) -> bool {
        true
    }
}

impl Fly for Pig {
    fn fly(&self) -> bool {
        false
    }
}

fn fly_static(s: impl Fly + Debug) -> bool {
    s.fly()
}

fn can_fly(s: impl Fly + Debug) -> impl Fly {
    if s.fly() {
        println!("{:?} can fly.", s);
    } else {
        println!("{:?} can't fly.", s);
    }

    s
}

fn dyn_can_fly(s: impl Fly + Debug + 'static) -> Box<dyn Fly> {
    if s.fly() {
        println!("{:?} can fly.", s);
    } else {
        println!("{:?} can't fly.", s);
    }

    Box::new(s)
}

fn main() {
    let pig = Pig;
    assert_eq!(fly_static(pig), false);
    let duck = Duck;
    assert_eq!(fly_static(duck), true);

    let pig = Pig;
    let pig = can_fly(pig);
    let duck = Duck;
    let duck = can_fly(duck);
}