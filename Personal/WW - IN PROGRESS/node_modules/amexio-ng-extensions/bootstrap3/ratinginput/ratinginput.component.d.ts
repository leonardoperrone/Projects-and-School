import { OnInit } from '@angular/core';
import { FormInputBase } from "../baseclass/form.base.class";
export declare const RATING_CONTROL_VALUE_ACCESSOR: any;
export declare const BASE_IMPL_RATING_INPUT: any;
export declare class RatingInputComponent extends FormInputBase implements OnInit {
    overStar: number;
    percent: number;
    max: number;
    stateOn: string;
    stateOff: string;
    readonly: boolean;
    percentageLabel: boolean;
    titles: string[];
    ratingStates: {
        stateOn: string;
        stateOff: string;
    }[];
    constructor();
    onChange: any;
    onTouched: any;
    range: any[];
    value: number;
    protected preValue: number;
    hoveringOver(value: number): void;
    resetStar(): void;
    onKeydown(event: any): void;
    ngOnInit(): void;
    writeValue(value: number): void;
    enter(value: number): void;
    reset(): void;
    registerOnChange(fn: (_: any) => {}): void;
    registerOnTouched(fn: () => {}): void;
    rate(value: number): void;
    protected buildTemplateObjects(ratingStates: any[], max: number): any[];
    isValidInput(): boolean;
}
