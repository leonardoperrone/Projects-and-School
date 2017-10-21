import { AfterViewInit, OnInit } from '@angular/core';
import { CarouselService } from "./carousel.service";
export declare class CarouselComponent implements OnInit, AfterViewInit {
    private carouselService;
    httpUrl: string;
    httpMethod: string;
    dataReader: string;
    scrollViewBindData: any;
    isContent: boolean;
    viewData: any[];
    elementId: any;
    className: any;
    response: any;
    constructor(carouselService: CarouselService);
    ngOnInit(): void;
    ngAfterViewInit(): void;
    setData(httpResponse: any): void;
}
