use std::cmp::{PartialOrd, Ordering};

fn cmp(lhs: &&f64, rhs: &&f64) -> Ordering {
    lhs.partial_cmp(rhs).unwrap()
}

fn main() {
    println!("{:?}", [-2, 0, 1, -2, -5].iter().max());
    println!("{:?}", [-2, 0, 1, -2, -5].iter().min());

    let numbers = [1.0, 4.0, 2.0];
    println!("{:?}", numbers.iter().max_by(cmp));
    println!("{:?}", numbers.iter().min_by(cmp));

    // let numbers = [1.0, 3.0, str::f64::NAN, 2.0];
    // println!("{:?}", numbers.iter().max_by(cmp));
}