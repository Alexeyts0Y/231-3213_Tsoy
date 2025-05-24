package com.tsoy.backend.service;

import java.util.List;

import org.springframework.stereotype.Service;

import com.tsoy.backend.entity.Bike;
import com.tsoy.backend.repository.BikeRepository;

import lombok.RequiredArgsConstructor;

@Service
@RequiredArgsConstructor
public class BikeService {
    
    private final BikeRepository repository;

    public List<Bike> getAll() {
        return repository.findAll(); 
    }

    public Bike getById(Long id) {
        return repository.findById(id)
                         .orElseThrow(() -> new RuntimeException("Exception"));
    }

    public Bike create(Bike bike) {
        return repository.save(bike);
    }

    public Long delete(Long id) {
        repository.deleteById(id);
        return id;
    }

    public Bike update(Long id, Bike updatedBike) {
        Bike bike = repository.findById(id).get();
        
        bike.setName(updatedBike.getName());
        bike.setBrand(updatedBike.getBrand());
        bike.setColor(updatedBike.getColor());
        bike.setPrice(updatedBike.getPrice());
        bike.setWeight(updatedBike.getWeight());
        bike.setImageUrl(updatedBike.getImageUrl());
        bike.setDescription(updatedBike.getDescription());
        
        return repository.save(bike);
    }
}
