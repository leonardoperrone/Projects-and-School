import { EventEmitter, OnChanges, OnInit, SimpleChanges } from '@angular/core';
export declare class ButtonGroupActionComponent implements OnInit, OnChanges {
    label: string;
    icon: string;
    type: string;
    onClickRoute: string;
    tooltipMessage: string;
    disabled: boolean;
    isLoading: boolean;
    size: string;
    block: boolean;
    fieldName: string;
    btnStyleClass: string;
    iconStyleClass: string;
    btnSizeStyleClass: string;
    elementId: any;
    hasToolTip: boolean;
    onClick: EventEmitter<any>;
    constructor();
    ngOnInit(): void;
    ngOnChanges(change: SimpleChanges): void;
    ngAfterViewInit(): void;
}
