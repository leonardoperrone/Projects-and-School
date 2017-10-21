import { OnInit } from '@angular/core';
export declare class ProgressComponent implements OnInit {
    showProgress: boolean;
    infinteMode: boolean;
    minValue: string;
    maxValue: string;
    currentValue: string;
    displayText: string;
    constructor();
    ngOnInit(): void;
}
