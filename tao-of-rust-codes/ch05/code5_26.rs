fn compute(input: &u32, output: &mut u32) {
    let cached_input = *input;

    if cached_input > 10 {
        *output = 2;
    } else if cached_input > 5 {
        *output *= 2;
    }
}

fn main() {
    let i = 20;
    let mut o = 5;

    compute(&i, &mut o);
    println!("{:?}", o);
}