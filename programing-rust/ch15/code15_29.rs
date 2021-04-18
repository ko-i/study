fn main() {
    let a = [5, 6, 7, 8, 9, 10];

    println!("Count a: {:?}", a.iter().fold(0, |n, _| n + 1));
    println!("Sum a: {:?}", a.iter().fold(0, |n, i| n + i));
    println!("Product a: {:?}", a.iter().fold(1, |n, i| n * i));

    println!("Max a: {:?}", a.iter().fold(i32::min_value(), |m, &i| std::cmp::max(m, i)));
}