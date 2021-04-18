use std::collections::HashSet;

fn main() {
    let squares = [4, 9, 16, 25, 36, 49, 64];
    let (power_of_two, impure): (HashSet<i32>, HashSet<i32>) =  squares.iter().partition(|&n| n & (n - 1) == 0);
    println!("{:?}", power_of_two);
    println!("{:?}", impure);

    let (upper, lower): (String, String) = "Great Teacher Onizuka".chars().partition(|&c| c.is_uppercase());
    println!("{:?}", upper);
    println!("{:?}", lower);
}