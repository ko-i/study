struct Point {
    x: i32,
    y: i32,
    z: i32,
}

fn main() {
    let origin = Point {x: 0, y: 0, z: 0};

    match origin {
        Point {x, ..} => println!("x is {}", x),
    }

    let numbers = (2, 4, 6, 8, 10);
    match numbers {
        (first, .., last) => println!("first: {}, last: {}", first, last),
    }

    let num = Some(4);

    match num {
        Some(x) if x < 5 => println!("less than five: {}", x),
        Some(x) => println!("{}", x),
        None => (),
    }

    let x = 4;
    let y = false;
    match x {
        4 | 5 | 6 if y => println!("yes"),
        _ => println!("no"),
    }
}