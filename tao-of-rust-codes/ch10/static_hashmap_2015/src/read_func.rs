use static_kv;

pub fn read_kv() {
    let ref m = static_kv::MAP;

    println!("{:?}", *m.get(&0).unwrap_or(&static_kv::NF));
    println!("{:?}", *m.get(&1).unwrap_or(&static_kv::NF));
}

pub fn rw_mut_kv() -> Result<(), String> {
    {
        let m = static_kv::MAP_MUT.read().map_err(|e| e.to_string())?;

        println!("{:?}", *m.get(&0).unwrap_or(&static_kv::NF));
    }

    {
        let mut m = static_kv::MAP_MUT.write().map_err(|e| e.to_string())?;

        m.insert(1, "baz");
    }

    Ok(())
}