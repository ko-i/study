fn largest<T: PartialOrd + Copy>(list: &[T]) -> T {
    let mut largest = list[0];

    for &item in list.iter() {
        if item > largest {
            largest = item;
        }
    }

    largest
}

fn largest_no_copy<T: PartialOrd>(list: &[T]) -> &T {
    let mut largest: &T = &list[0];

    for item in list.iter() {
        if item > largest {
            largest = &item;
        }
    }

    largest
}

fn main() {
    let number_list = vec![23, 32, 43, 63, 435];

    let result = largest(&number_list);
    println!("The largest number is {}", result);

    let result = largest_no_copy(&number_list);
    println!("The largest number is {}", result);

    let char_list = vec!['s', 'f', 'd', 'z', 'u'];

    let result = largest(&char_list);
    println!("The largest char is {}", result);
}