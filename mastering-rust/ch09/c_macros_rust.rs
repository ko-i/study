macro_rules! switch {
    ($a: expr, $b: expr) => {
        temp = $b; $b = &a; $a = $temp;
    };
}

fn main() {
    let x = 1;
    let y = 2;
    let temp = 3;
    switch!(x, y);

    println!("{} {} {}", x, y, temp);
}