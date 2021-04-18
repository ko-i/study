fn capitalize(data: &mut [char]) {
    // do somthing
}

fn foo() {
    let mut data = vec!['a', 'b', 'c'];
    let slice = &mut data[..];

    capitalize(slice);

    data.push('d');
}

fn main() {
    
}