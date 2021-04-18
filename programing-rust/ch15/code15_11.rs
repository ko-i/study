fn main() {
    let iter = (0..10).scan(0, |sum, item| {
        *sum += item;

        if *sum > 10 {
            None
        } else {
            Some(item * item)
        }
    });

    println!("{:?}", iter.collect::<Vec<i32>>());
}