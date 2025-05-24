package com.tsoy.backend.controller;

import org.springframework.web.bind.annotation.RestController;

import com.tsoy.backend.entity.Bike;
import com.tsoy.backend.service.BikeService;

import io.swagger.v3.oas.annotations.Operation;
import io.swagger.v3.oas.annotations.tags.Tag;
import lombok.RequiredArgsConstructor;

import java.util.List;

import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.PutMapping;

@RestController
@RequiredArgsConstructor
@RequestMapping("/api")
@CrossOrigin(origins = "http://localhost")
@Tag(name = "Bike API", description = "Управление велосипедами")
public class BikeController {
    
    private final BikeService service;

    @GetMapping("/bikes")
    @Operation(summary = "Получить все велосипеды", description = "Возвращает данные всех велосипедов")
    public List<Bike> getAll() {
        return service.getAll();
    }
    
    @GetMapping("/bikes/{id}")
    @Operation(summary = "Получить велосипед по ID", description = "Возвращает данные велосипеда")
    public Bike getById(@PathVariable Long id) {
        return service.getById(id);
    }
    
    @PostMapping("/bikes")
    @Operation(summary = "Создать велосипед")
    public Bike create(@RequestBody Bike bike) {
        return service.create(bike);
    }
    
    @PutMapping("/bikes/{id}")
    @Operation(summary = "Обновить велосипед", description = "Возвращает обновленный велосипед")
    public Bike update(@PathVariable Long id, @RequestBody Bike updatedBike) {
        return service.update(id, updatedBike);
    }

    @DeleteMapping("/bikes/{id}")
    @Operation(summary = "Удалить велосипед", description = "Возвращает ID удаленного велосипеда")
    public Long delete(@PathVariable Long id) {
        return service.delete(id);
    }
}