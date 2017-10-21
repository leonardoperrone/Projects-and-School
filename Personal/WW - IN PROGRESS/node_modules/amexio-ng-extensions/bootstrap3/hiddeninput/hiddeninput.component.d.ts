import { OnInit } from "@angular/core";
import { ControlValueAccessor } from "@angular/forms";
export declare const CUSTOM_HIDDENINPUT_CONTROL_VALUE_ACCESSOR: any;
export declare class HiddenInputComponent implements OnInit, ControlValueAccessor {
    elementId: string;
    constructor();
    ngOnInit(): void;
    private innerValue;
    private onTouchedCallback;
    private onChangeCallback;
    value: any;
    writeValue(value: any): void;
    registerOnChange(fn: any): void;
    registerOnTouched(fn: any): void;
}
